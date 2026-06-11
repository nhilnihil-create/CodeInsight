#include<iostream>
#include<string>
using namespace std;
int main(){
    int ans = 0;
    char t;
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0 ; i<n ; i++){
        int count = 0;
        for(int j=i;j<n;j++){
            t = s[j];
            if (t == 'A' || t == 'C' || t == 'G' || t == 'T') {
                count++;
            } else {
                break;
            }
        }
        if(ans < count)ans = count;
    }
    cout << ans << endl;
    return 0;
}