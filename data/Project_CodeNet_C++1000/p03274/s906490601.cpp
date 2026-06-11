#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n ,k;
    long long dist,mini = -1;
    cin >> n >> k;
    vector<long long>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    for(int i = 0;i <= n - k;i++){
        dist = min(abs(a[i]),abs(a[i + k - 1]));
        if(mini != -1)mini = min(mini,dist + abs(a[i + k - 1] - a[i]));
        else mini = dist + abs(a[i + k - 1] - a[i]);
    }
    cout << mini << endl;
}
