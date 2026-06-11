#include <bits/stdc++.h>

#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

bool cmp(P a, P b)
{
  if(a.first!=b.first)
    return a.first < b.first; 
  else
    return a.second < b.second;
}

int main()
{
  int N;
  cin >> N;
  
  vector<P> ab(N), cd(N);
  for(int i=0; i<N; i++)
    cin >> ab[i].first >> ab[i].second;
  for(int i=0; i<N; i++)
    cin >> cd[i].first >> cd[i].second;

  sort(ab.begin(), ab.end(), cmp);
  reverse(ab.begin(), ab.end());
  sort(cd.begin(), cd.end(), cmp);

  
  ll count = 0;
  
  for(int i=0; i<N; i++)
    {
      int index=-1;
      int ymax=1000;
      for(int j=0; j<N; j++)
	{
	  if(ab[i].first < cd[j].first && ab[i].second < cd[j].second)
	    {
	      if(ymax>cd[j].second)
		{
		  ymax=cd[j].second;
		  index=j;
		}
	    }
	}
      if(index!=-1){
	cd[index] = P(-1, -1);
	count++;
      }
    }

  cout << count << endl;
  
  
  


  return 0;
}


//cout << setprecision(13);
//next_permutation();
//__gcd();
//reverse();
//set ,tuple ,pair;
//bitset
//vector.find
//vector.count

