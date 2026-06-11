#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long beki[35];
    beki[0] = 1;
    for(int i=1;i<35;i++){
        beki[i] = beki[i-1] * 2;
    }
    long a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    map<long,int>m;
    for(int i=0;i<n;i++){
        m[a[i]]++;
    }
    int ans = 0;
    for(int i=n-1;i>0;i--){
        if(m[a[i]] > 0){
            long makeBeki = 0;
            // bool bekibeki = false;
            for(int j=34;j>0;j--){
                if(a[i] >= beki[j-1]){
                    makeBeki = beki[j];
                    break;
                }
            }

            // cout << a[i] << " "<<makeBeki<<endl;

            
            if(a[i] == makeBeki-a[i]){
                if(m[a[i]]>=2){
                    m[a[i]]-=2;
                    ans++;
                }
            }else{
                if(m[makeBeki-a[i]]>=1){
                    m[a[i]]--;
                    m[makeBeki-a[i]]--;
                    ans++;
                }

            }
        }
    }
    cout << ans << endl;
}