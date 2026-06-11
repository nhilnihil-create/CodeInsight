#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int N, sum = 0;
    cin >> N;
    vector<Pint> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i).first;
        sum += A.at(i).first;
        A.at(i).first *= N;
        A.at(i).second = i;
    }
    for (int i = 0; i < N; i++){
        A.at(i).first = abs(A.at(i).first - sum);
    }
    sort(ALL(A));
    cout << A.at(0).second << endl;
}

