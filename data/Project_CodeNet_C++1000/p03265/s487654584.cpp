#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct point{int x,y;};

int main(){
    vector<point> p(4);
    for(int i=0;i<2;i++){
        cin >> p[i].x >> p[i].y;
    }
    point v;
    v.x = p[1].x - p[0].x;
    v.y = p[1].y - p[0].y; 

    p[2].x = p[1].x - v.y;
    p[2].y = p[1].y + v.x;

    p[3].x = p[2].x - v.x;
    p[3].y = p[2].y - v.y;
    cout << p[2].x << " " << p[2].y << " " << p[3].x << " " << p[3].y << endl;
}