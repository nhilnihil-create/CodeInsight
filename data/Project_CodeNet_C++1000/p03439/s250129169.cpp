#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<string> v(N);
    int Q = 20;
    cout << 0 << endl;
    cin >> v[0];
    if(v[0]=="Vacant") return 0;
    Q--;
    int high = N;
    int low = 0;
    int mid;
    while(Q--) {
        mid = (high + low) / 2;
        cout << mid << endl;
        cin >> v[mid];
        if(v[mid]=="Vacant") return 0;
        if((v[low]==v[mid]&&(mid-low)%2==0)||(v[low]!=v[mid]&&(mid-low)%2!=0)) low = mid;
        else high = mid; 
    }
    return 0;
}