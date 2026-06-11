#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int req1=a.back()/2,req2=(a.back()+1)/2;
    int cur = INT_MAX, curi;
    for(int i=0;i<n;i++){
        int val = min(abs(req1-a[i]),abs(req2-a[i]));
        if(val<cur){
            cur=val;
            curi=i;
        }
    }
    cout << a.back() << " " << a[curi] << endl;
    return 0;
}