#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int res=0, cnt=0;
    while(x>0){
        if(cnt<=n-1){
            if(x >= a.at(cnt)){
                x = x - a.at(cnt);
                res++; cnt++;
            }else{
                break;
            }   
        }else{
            break;
        }
    }
    if(res == n && x==0)
        cout << res << endl;
    else if(res == n && x!=0)
        cout << (res-1) << endl;
    else
        cout << res << endl;
    
    return 0;
}