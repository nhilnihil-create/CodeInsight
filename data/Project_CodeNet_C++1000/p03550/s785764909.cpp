#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n, z, w;
    cin >> n >> z >> w;
    vector<int> v(n);
    //vector< pair<int, int> > abs_v(n-1);
    for(int i = 0; i < n; i++) cin >> v[i];

    if(n == 1) cout << abs(w-v[0]) << endl;
    else{
        int a = abs(w-v[n-1]);
        int b = abs(v[n-1] - v[n-2]);
        cout << ((a > b)? a : b) << endl;
    }

}