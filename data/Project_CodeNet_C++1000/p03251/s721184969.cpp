#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
using namespace std;


int main()
{
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N),y(M);
    for (int i = 0; i < N; i++) cin >> x[i];
    for (int j = 0; j < M; j++) cin >> y[j];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(x[N - 1] < y[0] && X < y[0] && Y >= y[0])
    {
        cout << "No War" << endl;
    }
    else
    {
        cout << "War" << endl;
    }

}