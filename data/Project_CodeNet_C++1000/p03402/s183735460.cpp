#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const char W = '.';
const char B = '#';

int main(){
    ll a, b;
    cin >> a >> b;

    const ll na = 2 * (a - 1 + 49) / 50;
    const ll nb = 2 * (b - 1 + 49) / 50;

    vector<vector<char>> map(na + nb, vector<char>(100, W));
    for(int i = 0; i < na; ++i){
        fill(map.at(i).begin(), map.at(i).end(), B);
    }
    a--; b--;
    for(int i = 0; a > 0; i += 2){
        for(int j = 0; j < map.at(i).size() && a > 0; j += 2){
            map.at(i).at(j) = W;
            a--;
        }
    }
    for(int i = na + 1; b > 0; i += 2){
        for(int j = 0; j < map.at(i).size() && b > 0; j += 2){
            map.at(i).at(j) = B;
            b--;
        }
    }

    cout << map.size() << ' ' << map.at(0).size() << endl;
    for(int i = 0; i < map.size(); ++i){
        for(int j = 0; j < map.at(i).size(); ++j){
            cout << map.at(i).at(j);
        }
        cout << endl;
    }
    return 0;
}
