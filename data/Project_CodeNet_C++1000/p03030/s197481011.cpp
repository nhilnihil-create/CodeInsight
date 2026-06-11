#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int i,N;
    string city;
    int point;
    cin >> N;
    pair<pair<string,int>,int> p[N];
    for(i=0;i<N;i++){
        cin >> city >> point;
        p[i] = make_pair(make_pair(city,-1*point),i);
    }
    sort(p,p+N);
    
    for(i=0;i<N;i++){
        cout << p[i].second + 1 << endl;
    }
    return 0;
}
