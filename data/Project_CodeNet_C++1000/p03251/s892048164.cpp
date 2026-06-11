#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <map>
using namespace std;
typedef long long int lli;
#define urept(soeji, start, n) for (int soeji = start; soeji < n; soeji++)
#define drept(soeji, start, n) for (int soeji = start; soeji > n; soeji--)

int main(void)
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x;
    vector<int> y;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        x.push_back(tmp);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> tmp;
        y.push_back(tmp);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
  	bool f = false;
    for (int i = x[N-1]+1; i <= y[0]; i++)
    {
        if (X < i && i <= Y)
        {
          f = true;
          break;
        }
    }
  	if(f==true){
    cout << "No War" <<endl;
    }else{
    cout << "War" << endl;
    }
    return 0;
}