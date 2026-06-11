#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

using namespace std;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

struct Point {
    int x;
    int y;
    int d;
    Point(){}
    Point(int x, int y, int d) {
        this-> x = x;
        this-> y = y;
        this-> d = d;
    }
};

int main(){
    int h,w; cin >> h >> w;
    int white = 0;
    vector<int> table[h];
    vector<int> visited[h];
    rep(i, h) {
        rep(j, w) {
            char c; cin >> c;
            if(c == '.') {
                table[i].push_back(0);
                white++;
            }
            else{
                table[i].push_back(1);
            }
            visited[i].push_back(0);
        }
    }
    queue<Point> q;
    q.push(Point(0,0,1));
    int shortest = -1;
    while(!q.empty()) {
        Point p = q.front();
        q.pop();
        if(p.x < 0 || p.x >= h || p.y < 0 || p.y >= w)
            continue;
        if(table[p.x][p.y])
            continue;
        if(visited[p.x][p.y])
            continue;
        visited[p.x][p.y] = 1;
        if(p.x == h-1 && p.y == w-1) {
            shortest = p.d;
            break;
        }
        q.push(Point(p.x-1, p.y, p.d+1));
        q.push(Point(p.x+1, p.y, p.d+1));
        q.push(Point(p.x, p.y-1, p.d+1));
        q.push(Point(p.x, p.y+1, p.d+1));
    }
    if(shortest == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << white - shortest << endl;
}
