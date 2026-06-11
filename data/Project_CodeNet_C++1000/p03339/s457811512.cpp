#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> esum(n, 0);
    vector<int> wsum(n, 0);
    if(s[0] == 'E') esum[0] = 1;
    else wsum[0] = 1;
    for(int i = 1; i < n; i++){
        esum[i] = esum[i-1];
        wsum[i] = wsum[i-1];
        if(s[i] == 'E') esum[i]++;
        else wsum[i]++;
    }

    int ans = 1001001001;
    for(int i = 0; i < n; i++){
        int coans = 0;
        if(i != 0) coans += wsum[i-1];
        if(i != n-1) coans += esum[n-1]-esum[i];
        if(ans > coans) ans = coans;
    }
    cout << ans << endl;
    return 0;
}