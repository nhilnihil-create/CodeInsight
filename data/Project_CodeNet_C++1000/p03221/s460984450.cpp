#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

bool cmp0 (const tuple<int,int,int> &p1, const tuple<int,int,int> &p2)
{
  return get<0>(p1) < get<0>(p2);
}

bool cmp1 (const tuple<int,int,int> &p1, const tuple<int,int,int> &p2)
{
  return get<1>(p1) < get<1>(p2);
}

bool cmp2 (const tuple<int,int,int> &p1, const tuple<int,int,int> &p2)
{
  return get<2>(p1) < get<2>(p2);
}


int main ()
{
  int N,M,P,Y,rank,cn;
  vector<tuple<int,int,int> > vt;

  cin >> N >> M;  

  vector<int> Prank(N+1);
  vector<string> id(M);
  ostringstream oss;

  REPI(N+1)
    Prank[i] = 1;

  REPI(M)
  {
    cin >> P >> Y;
    vt.emplace_back (i,P,Y);
  }

  sort(vt.begin (),vt.end (), cmp2);

  REPI(M)
  {
    oss.str("");
    oss.clear();
    P = get<1>(vt[i]);
    rank = Prank[P];
    Prank[P]++;
    cn = get<0>(vt[i]);
    oss << setfill('0') << right <<  setw(6) << P;
    oss << setfill('0') << right <<  setw(6) << rank;
    id[cn] = oss.str ();
  }

  sort(vt.begin (),vt.end (), cmp0);
  
  REPI(M)
    cout << id[i] << endl;
  return 0;
}