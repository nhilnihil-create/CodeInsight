#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define f first
#define s second
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    set<string> st;
    int k; cin >> k;
    for(int i = 1; i <= k; i++){
        for(int j = i+1; j <= k; j++){
            string t = to_string(i); t += " ";
            if((j%2 == 0 && i%2 == 1) || (i%2 == 0 && j%2 == 1)){
                t += to_string(j); st.insert(t);
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}
