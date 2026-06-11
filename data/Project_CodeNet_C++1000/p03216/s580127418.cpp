#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL LINF=1LL<<62;
const LL mod=1e9+7;




int main(){
    int n,q;
    string s;
    cin >> n >> s >> q;
    for (int p = 0; p < q; p++) {
        int k;cin >> k;
        LL ans=0;
        vector<LL> m(n+1,0);
        for (int i = 0; i < n; i++) {
            m[i+1]=m[i]+(s[i]=='M'?1:0);
        }
        LL sum=0;
        queue<LL> que;
        for (int i = n-1; i >= 0; i--) {
            if(!que.empty()&&que.front()-k>=i){
                sum-=m[que.front()+1]-m[i+1];
                que.pop();
            }
            if(s[i]=='C'){
                que.push(i);
            }
            else if(s[i]=='M'){
                sum+=que.size();
            }
            else if(s[i]=='D'){
                ans+=sum;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
