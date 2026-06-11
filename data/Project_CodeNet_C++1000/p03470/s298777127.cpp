#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, ans = 1;
    cin >> n;
    vector<int> d(n);

    for(int i = 0; i < n; ++i){
        cin >> d.at(i);
    }
    sort(d.begin(),d.end());
    reverse(d.begin(),d.end());
    for(int i = 0; i < n; ++i){
        if(i>0 && d.at(i-1) != d.at(i))
            ans++;
    }
    cout << ans << endl;
}
