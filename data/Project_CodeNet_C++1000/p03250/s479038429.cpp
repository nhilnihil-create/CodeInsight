#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> array(3);
    array[0] = A;
    array[1] = B;
    array[2] = C;
    sort(array.begin(), array.end());
    int t = 0;
    t = array[2] * 10 + array[1];
    cout << t + array[0] << endl;
}