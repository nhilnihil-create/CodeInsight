#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005



int main() {
    int n;
    cin >> n;

    int ans[n];
    if(n==3){
        ans[0] = 2; ans[1] = 5; ans[2] = 63;
    }else if(n<=15002){
        rep(i,n-2){
            ans[i] = (i+1)*2;
        }
        int x = n-2;
        if((n-2)%2==1)x = n-1;
        while(x%2==0){
            x /= 2;
        }
        if(x==1){
            x = n-2;
            if((n-2)%2==0){
                x = n-1;
            }
        }
        ans[n-2] = x;
        ans[n-1] = x*3;
    }else{
        int count = 0;
        int sum = 0;
        srep(i,1,30000){
            if(i%6==0)continue;
            if(i%2==0 || i%3==0){
                ans[count] = i;
                sum += i;
                count++;
            }
        }
        rep(i,n - 15002){
            ans[count] = 6*(i+1);
            sum += ans[count];
            count++;
        }
        ans[n-2] = 7;
        ans[n-1] = 35;
        if(sum%7!=0){
            if(n<17500){
                while(sum%7!=0){
                    ans[n-3] += 6;
                    sum += 6;
                }
            }else{
                sum += 30000 - ans[15000];
                ans[15000] = 30000;
                int i = 15000;
                while(sum%7!=0){
                    ans[i] = ans[i+1] - 6;
                    ans[i+1] = 30000;
                    sum -= 6;
                    i++;
                }
            }
        }
    }

    rep(i,n){
        cout << ans[i] << ' ';
    }
    cout << endl;
    
    return 0;
}
 
 
