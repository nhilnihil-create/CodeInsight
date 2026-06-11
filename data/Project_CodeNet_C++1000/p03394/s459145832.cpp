#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int N;
    cin >> N;
    ll sum = 0;
    int cnt = 0;
    vector<int> s;
    if (N == 3) {
        cout << "2 5 63\n";
        return 0;
    }
    
    for (int i = 2; i <= 30000; i++) {
        if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
            s.push_back(i);
            sum += i;
            cnt++;
        }
        if (cnt == (N - 2)) break;
    }
    for (int i = 29900; i <= 29999; i++) {
        bool check = false;
        for (int j = i+1; j <= 30000; j++) {
            if ((sum+i+j) % 30 != 0) continue;
            if ((i % 2 == 0 || i % 3 == 0 || i % 5 == 0) && (j % 2 == 0 || j % 3 == 0 || j % 5 == 0)){
                s.push_back(i);
                s.push_back(j);
                check = true;
                break;
            }
        }
        if (check) break;
    }
    for (int i = 0; i < N; i++) {
        if (i < N-1) printf("%d ", s[i]);
        else printf("%d\n", s[i]);
    }
}
