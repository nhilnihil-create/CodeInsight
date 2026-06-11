#include <bits/stdc++.h>
#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

using namespace std;

int main(){
    io

    int n,t,a;
    cin >> n >> t >> a;
    
    double min(100000);
    int index;
    for(int i(0); i<n; i++){
        double x; cin >> x;
        x = t - (x * 0.006);
        if(abs(a - x) < min){
            min = abs(a - x);
            index = i;
        }
    }
    cout << index + 1 << ENDL;
 
    return 0;
}