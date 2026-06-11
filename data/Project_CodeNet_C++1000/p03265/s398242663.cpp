#include <iostream>
using namespace std;
struct point{
    int x,y;
};
point rot(int x, int y){
    point ans;
    ans.x = -y;
    ans.y = x;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    point a,b;
    cin >> a.x >> a.y >> b.x >> b.y;
    point p = rot(b.x - a.x, b.y - a.y);
    cout << b.x + p.x << " " << b.y + p.y << " " << a.x + p.x << " " << a.y + p.y << endl;
    return 0;
}