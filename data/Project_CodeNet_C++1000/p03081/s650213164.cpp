#include <bits/stdc++.h>


using namespace std;

const int MAXN = 200010;
string S;
vector<pair< char, char> > Q;
int t;
int N;

bool check(int index, bool direcction) {
    char c = S[index];
   
    for (auto it: Q) { 
        //cout << c << " " << index << endl;
        if (c == it.first) {
            
            if (it.second == 'L') {
                index--;
            } else {
                index++;
            }

            if (direcction) {
                if (index < 1) return true;
            } else {
                if (index > N) return true;
            }
            // if (index < 1 || index > N) return true; 
            c = S[index];
        }
    }

    return false;
}

int find_me(int left ,int right, bool direction) {
    int ans = left - 1;
    if (!direction) ans = right + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, direction)) {
            ans = mid;
            if (direction) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if (direction) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    } 
    

    return ans;
}

int main() {

    cin >> N >> t;
    cin >> S;

    S = "0" + S + "0";
    for (char a,b;t--;) {
        cin >> a >> b;
        Q.push_back({a,b});
    }
    int rs = find_me(1, N, true);
    int lim = rs;

    // for (int i = 1; i <= N; i++) {
    //     if (check(i, true)) {
    //         rs = i;
    //         lim = i;
    //     } else {
    //         break;
    //     }
    // }

     int rs2 = N - find_me(lim + 1, N, false) + 1;
    // for (int i = N; i > lim; i--) {
    //     if(check(i, false)) {
    //         rs2 = N - i  + 1;
    //     } else break;
    // }

    //cout << rs << " " << rs2 <<endl;

    cout<< N - (rs +rs2);
    //cout << check(2, true);

    return 0;
}