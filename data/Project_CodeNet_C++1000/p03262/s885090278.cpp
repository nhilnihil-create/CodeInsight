#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    int r;
    while(r=a%b){
        a = b;
        b = r;
    }
    return b;
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n+1);
    vector<int> sub;
    v[0] = x;
    int min = x;
    for(int i = 1; i < n+1; i++){
        cin >> v[i];
        //cout << v[i] << endl;
        if(v[i] < min) min = v[i];
    }
    //cout << min << endl;
    for(int i = 0; i < n+1; i++){
        if(v[i]-min != 0){
            sub.push_back(v[i]-min);
        }
    }
    if(sub.size() == 1) cout << sub[0] << endl;
    else{
        int ans = gcd(sub[0], sub[1]);
        for(int i = 2; i < n; i++){
            ans = gcd(ans, sub[i]);
        }
        cout << ans << endl;
    }
}