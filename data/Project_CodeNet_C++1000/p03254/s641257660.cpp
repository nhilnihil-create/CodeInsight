#include <iostream>
#include <algorithm>
using namespace std;

long long n, x, total=0, ans=-1;

int main(){
    cin >> n >> x;
    long long a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        x-=a[i];
        if(x<0){
            ans=i;
            break;
        }
    }
    if(x==0){
        cout << n << endl;
    }
    else if(x>0){
        cout << n-1 << endl;
    }
    else{
        cout << ans << endl;
    }
}
