#include <iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int p[102];
    int d[3] {0};
    for(int i = 0; i < n; i++){
        cin >> p[i];
        if(p[i] <= a) d[0]++;
        else if(p[i] <= b) d[1]++;
        else d[2]++;
    }
    cout << min(d[0], min(d[1], d[2])) << endl;
}