#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    double a[N];
    double sum = 0;
    for(int i = 0; i < N;i++)cin >> a[i],sum += a[i];
    
    double ave = sum/N;
    
    double mn = INT_MAX;
    double ans = 0;
    for(int i = 0; i < N-1;i++){
        
        if(mn >abs(a[i]-ave)){
            mn = abs(a[i]-ave);
            ans = i;
        }
        
    }
    cout << ans <<endl;
}
    
    

