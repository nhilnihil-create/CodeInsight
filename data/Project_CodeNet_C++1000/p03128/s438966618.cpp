#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;


class Match {
   public:
   vector<int> fNarabi;
   Match(){;}
   void Add(int a) {fNarabi.push_back(a);}
   void Dump(void){
      for (int i = fNarabi.size()-1;i>=0;i--) {
         cout<<fNarabi[i];
      }
      cout<<endl;
   }
   bool operator<(const Match& c1)const
   {
      if (fNarabi.size() == c1.fNarabi.size()) {
         for (int i = fNarabi.size()-1;i>=0;i--) {
            if (fNarabi[i]!=c1.fNarabi[i]) return (fNarabi[i]<c1.fNarabi[i]);
         }
         return false;
      } else return (fNarabi.size() < c1.fNarabi.size());
   }
};

const int MAXN = 10010;
Match dp[MAXN];
set<int> A;
int Nneed[9] = {2,5,5,4,5,6,3,7,6};

void Update(int i) {
   Match ne = Match();
   Match ne_cd;
   rep(j,1,10) {
      if (i-Nneed[j-1]==1) continue;
      if (A.count(j) && i-Nneed[j-1]>=0) {
         ne_cd = dp[i-Nneed[j-1]];
         if (ne_cd.fNarabi.size()==0) continue;
         ne_cd.Add(j);
         chmax(ne,ne_cd);
      }
   }
   chmax(dp[i],ne);
   return;
}

int main(void) {
   int N,M;
   cin>>N>>M;
   int a;
   rep(j,0,M) {
      cin>>a;
      A.insert(a);
   }
   dp[0] = Match();
   for (auto el: A) {
      Match ne;
      ne.Add(el);
      chmax(dp[Nneed[el-1]],ne);
   }
   rep(i,2,N+1) {
      Update(i);
      // cout<<i<<" ";
      // dp[i].Dump();
   }
   dp[N].Dump();



   return 0;
}