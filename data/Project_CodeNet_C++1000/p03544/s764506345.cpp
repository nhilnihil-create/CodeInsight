#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> lucas;

    lucas.push_back(2);
    lucas.push_back(1);

    for(int i=2; i<=N; i++){
        lucas.push_back(lucas.at(i-1)+lucas.at(i-2));
    }

    cout << lucas.at(N) << endl;

    return 0;
}