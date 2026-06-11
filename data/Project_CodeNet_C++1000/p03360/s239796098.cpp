#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C, K, Sum = 0;
    vector<int> v;
    cin >> A >> B >> C >> K;

    v.push_back(A);
    v.push_back(B);
    v.push_back(C);

    for (int i = 0; i < K; i++)
    {
        sort(v.begin(), v.end(),greater<>());
        v[0] = v[0] * 2;
    }

    for (int i = 0; i < v.size(); i++)
    {
        Sum += v[i];
    }
  
  cout << Sum;

}