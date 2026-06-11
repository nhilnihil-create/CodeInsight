#include <iostream>

using namespace std;

int main(){
    string s;
    int n;
    int cnt =0;
    cin >> s;
    n = s.length();
    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }
    if(n%2 == 0){
        for(int i = 0; i < n/2; i++){
            if(s[n/2-1 -i] == s[n/2 + i] && s[n/2-1 -i] == s[n/2-1]){
                cnt++;
            }else{
                cnt += n/2;
                break;
            }
            if(i == n/2-1){
                cnt += n/2;
                break;
            }
        }
    }else{
        for(int i = 1; i <= (n-1)/2; i++){
            if(s[(n-1)/2 -i] == s[(n-1)/2 + i] && s[(n-1)/2 + i] == s[(n-1)/2]){
                cnt++;
            }else{
                cnt += (n + 1)/2;
                break;
            }
            if(i == (n-1)/2){
                cnt += (n + 1)/2;
                break;
            }
        }
    }
    cout << cnt << '\n';
}