#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

struct point{
    int x, y;
};
bool comp_x(const point a, const point b){
    return a.x < b.x;
}
bool comp_y(const point a, const point b){
    return a.y < b.y;
}

int main(){
    int n;
    cin >> n;
    vector<point> R(n), B(n);
    for(int i=0;i<n;i++){
        cin >> R[i].x >> R[i].y;
    }
    for(int i=0;i<n;i++){
        cin >> B[i].x >> B[i].y;
    }
    sort(R.begin(), R.end(), comp_y);
    sort(B.begin(), B.end(), comp_x);

    for(int i=0;i<n;i++){
        for(int j=R.size()-1;j>=0;j--){
            if(R[j].x < B[i].x && R[j].y < B[i].y){
                R.erase(R.begin()+j);
                break;
            }
        }
    }

    cout << n - R.size() << endl;
    return 0;
}