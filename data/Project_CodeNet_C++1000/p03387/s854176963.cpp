#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, c, ans=0, maxnum, minnum;
    cin >> a >> b >> c;
    while(1){
        if(a==b && b==c && a==c) break;
        maxnum=max({a, b, c});
        if(maxnum-a==1 || maxnum-b==1 || maxnum-c==1){
            if(maxnum==a){
                b++;
                c++;
            }
            else if(maxnum==b){
                a++;
                c++;
            }
            else{
                a++;
                b++;
            }
        }
        else{
            if(min({a, b, c})==a) a+=2;
            else if(min({a, b, c})==b) b+=2;
            else c+=2;
        }
        ans++;
    }
    cout << ans <<endl;
    return 0;
}