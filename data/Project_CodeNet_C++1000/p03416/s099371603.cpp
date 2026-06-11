#include <bits/stdc++.h>
using namespace std;

int check(int a, int ans){
    string str;
    str = std::to_string(a);
    if(str[0] == str[4] && str[1] == str[3]) ans++;
    return ans;
}

int main(){
    int A, B;
    cin >> A >> B;
    int A_c = A;
    int ans = 0;
    for(int i=0; i<B-A+1; i++) {
        ans = check(A_c, ans);
        A_c++;
    }

    cout << ans << endl;
}