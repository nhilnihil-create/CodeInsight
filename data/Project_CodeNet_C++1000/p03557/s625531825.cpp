#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
long long int N;cin >> N;
long long int count = 0;
vector<long long int> A(N);
vector<long long int> B(N);
vector<long long int> C(N);

    for(int i = 0; i < N; i++){

    cin >> A.at(i);

    }

    for(int i = 0; i < N; i++){

    cin >> B.at(i);

    }

    for(int i = 0; i < N; i++){

    cin >> C.at(i);

    }

sort(A.begin(), A.end());
sort(B.begin(), B.end());
sort(C.begin(), C.end());

    for(int j = 0; j < N; j++){

    count += (lower_bound(A.begin(), A.end(), B.at(j)) - A.begin())*
              (C.end() - upper_bound(C.begin(), C.end(), B.at(j)));

}
cout << count << endl;
}