#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, n) for (int i = 1; i < (int)(n+1); i++)
#define rep4(i, s, n) for (int i = (s); i < (int)(n+1); i++)
#define repr(i,n) for (int i = (n-1); i>=0;i--)
#define repr3(i,n) for(int i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF const ll INF = 1001001001;
#define PI const ld PI = 3.14159265358979323846;



int main() {
   int N;
   cin>>N;
   int b[N+1];
   rep3(i,N){
       cin>>b[i];
   }
   bool flag[N+1];
   int way[N+1];
   rep3(i,N){
       way[i]=-1;
   }
   rep3(i,N){
       flag[i]=false;
   }
   int flag_count;
   rep3(i,N){
       flag_count=0;
       rep3(j,N){
           if(flag[j]){
               flag_count++;
           }
           


       }
       repr3(j,N){
           if(flag[j]){
               flag_count--;
           }
           else if(flag_count+1==b[j]){
               way[i]=b[j];
               flag[j]=true;
               break;
           }
       }
       if(way[i]==-1){
           cout<<-1<<endl;
           return 0;
       }
   }
   rep3(i,N){
       cout<<way[i]<<endl;
   }

}