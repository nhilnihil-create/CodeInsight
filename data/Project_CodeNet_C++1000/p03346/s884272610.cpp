#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> p(n, 0), pos(n, 0);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) pos[--p[i]] = i;
    
    int ans = 1, str = 1;
    for(int i=1;i<n;i++){
        if(pos[i-1] <= pos[i]) str++;
        else str = 1;
        if(ans < str) ans = str;
    }
    cout << n-ans << endl;
}
