#include <bits/stdc++.h>
using namespace std;
// for(long long i = 0;i < num; i++){}
int main() {
    //
    long long num;
    long long cnt = 0;

    cin >> num;

    vector<long long> A(num);
    vector<long long> B(num);
    vector<long long> over;
    vector<long long> nEnough;

    for (int i = 0; i < num; i++) cin >> A.at(i);

    for (int i = 0; i < num; i++) {
        long long tmp;
        cin >> tmp;
        B.at(i) = tmp;

        if (A.at(i) > B.at(i))
            over.push_back(A.at(i) - B.at(i));
        else if (A.at(i) < B.at(i))
            nEnough.push_back(B.at(i) - A.at(i));
    }

    sort(over.rbegin(), over.rend());

    long long tmp2;
    long long lastIndex = -1;
    for (int i = 0; i < nEnough.size(); i++) {
        tmp2 = nEnough.at(i);
        cnt++;
        for (int j = 0; j < over.size(); j++) {
            if (over.at(j) == 0) continue;
            
            if (tmp2 <= over.at(j)) {
                over.at(j) -= tmp2;
                tmp2 = 0;
                if (lastIndex == -1) {
                    lastIndex = j;
                    cnt++;
                } else {
                    if (lastIndex != j) {
                        cnt++;
                        lastIndex = j;
                    }
                }
                break;
            } else {
                tmp2 -= over.at(j);
                over.at(j) = 0;
                if (lastIndex == -1) {
                    lastIndex = j;
                    cnt++;
                } else {
                    if (lastIndex != j) {
                        cnt++;
                        lastIndex = j;
                    }
                }
            }
        }

        if (tmp2 > 0) {
            cout << -1;
            return 0;
        }
    }

    cout << cnt;
    //
}
