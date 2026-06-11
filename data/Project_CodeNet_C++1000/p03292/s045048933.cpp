#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ALL(V) (V).begin(),(V).end()
 
int main()
{
    int a,b,c;
    cin >> a >>b>>c;
    vector<int> v {a,b,c};
    sort(ALL(v));
    int fir = v[2];
    int sec = v[1];
    int thi = v[0];
    cout << (fir - sec) + (sec - thi);
}