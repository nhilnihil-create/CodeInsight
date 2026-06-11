#include <bits/stdc++.h>
using namespace std;
// for(long long i = 0;i < num; i++){}
int main() {
    //
    int num, que;
    int cnt = 0;
    int st, end;
    string str;

    cin >> num >> que >> str;

    vector<int> vec(num+1, 0);

    for (int i = 0; i < num; i++) {
        if (i < num-1 && str.at(i) == 'A' && str.at(i + 1) == 'C') vec.at(i+1)= vec.at(i) + 1;
        else vec.at(i+1)  = vec.at(i);
    }

    for (int i = 0; i < que; i++) {
        cin >> st >> end;
        st--;
        end--;

        cout << vec.at(end) - vec.at(st) << endl;
    }

    //
}
