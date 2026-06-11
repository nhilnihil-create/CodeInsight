#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,max_a = -1,max_i = -1;
    cin >> n;
    vector<int> a(n);
    bool is_p = 0,is_n = 0;

    for(int i = 0;i < n;i ++){
        cin >> a[i];

        if(a[i]>=0) is_p = 1;
        else is_n = 1;
        
        if(max_a<abs(a[i])) {max_a = abs(a[i]);max_i = i;}
    }
    if(a[max_i]>=0) is_n = 0;
    else is_p = 0;

    cout << 2*(n-1) << endl;
    for(int i = 0;i < n;i ++){
        if(max_i!=i) cout << max_i+1 << " " << i+1 << endl;
    }
    if(is_p) for(int i = 0;i < n-1;i ++){
        cout << i+1 << " " << i+2 << endl;
    }
    else for (int i = n-1;i >= 1;i --){
        cout << i+1 << " " << i << endl;
    }

    return 0;
}