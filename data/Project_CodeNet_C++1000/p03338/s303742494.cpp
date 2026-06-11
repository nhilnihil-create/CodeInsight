#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans=0;
    rep(i,0,s.size()){
        string t = s.substr(0,i);
        string t_2 = s.substr(i);
        set<char> t_count;
        rep(j,0,t.size()){
            t_count.insert(t[j]);
        }
        int match = 0;
        rep(j,0,t_2.size()){
            if(t_count.count(t_2[j])){
                match ++;
                t_count.erase(t_2[j]);
            }
        }
        ans = max(ans,match);
    }
    cout<<ans<<endl;
  return 0;
}