#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int power2(long long a){
    int cnt=0;
    while(a%2==0){
        a/=2;
        cnt++;
    }
    return cnt;
}


int main(){
    int n;
    cin >> n;
    long long a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int ans=0;

    for(int i=0;i<n;i++){
        ans += power2(a[i]);
    }

    cout << ans << endl;
}

