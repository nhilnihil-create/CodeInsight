#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    int N;  cin >> N;
    string sl, sr;
    cout << 0 << endl;  cin >> sl;
    if(sl == "Vacant"){
        cout << 0 << endl;
        return 0;
    }
    cout << N-1 << endl;  cin >> sr;
    if(sr == "Vacant"){
        cout << N-1 << endl;
        return 0;
    }

    int left = 0, right = N - 1;
    while(true){
        int mid = (left + right)/2;
        string s;
        cout << mid << endl;  cin >> s;
        if(s == "Vacant"){
            cout << mid << endl;
            return 0;
        }

        if(((mid - left + 1)%2 == 0 && sl == s) || ((mid - left + 1)%2 == 1 && sl != s)){
            right = mid;
            sr = s;
        }else{
            left = mid;
            sl = s;
        }
    }
}