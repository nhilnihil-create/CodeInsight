#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

int main() {
    //cout.precision(10);
    vector<int> two_one, two_two, three, six;
    for(int i = 1; i <= 30000; i++){
        if((i == 2) || (i == 4) || (i == 3) || (i == 9)){
            continue;
        }
        if((i % 6) == 0){
            six.push_back(i);
            continue;
        }
        if((i % 3) == 0){
            three.push_back(i);
            continue;
        }
        if((i % 2) != 0){
            continue;
        }
        if((i % 3) == 1){
            two_one.push_back(i);
            continue;
        }
        two_two.push_back(i);
    }
    //cout << six.size() << " " << three.size() << " " << two_two.size() << " " << two_one.size() << endl;
    int n;
    cin >> n;
    if(n == 3){
        cout << "2 5 63" << endl;
        return 0;
    }
    if(n == 4){
        cout << "2 5 20 63" << endl;
        return 0;
    }
    cout << "2 4 3 9 ";
    int now = 4;
    if(n <= 5004){
        for(int i = 0; ; i++){
            cout << six[i] << " ";
            now++;
            if(now == n){
                break;
            }
        }
        cout << endl;
        return 0;
    }
    if(n <= 10002){
        for(int i = 0; i < three.size(); i++){
            cout << three[i] << " ";
            now++;
        }
        for(int i = 0; ; i++){
            cout << six[i] << " ";
            now++;
            if(now == n){
                break;
            }
        }
        cout << endl;
        return 0;
    }
    if(n <= 15002){
        for(int i = 0; i < 4999; i++){
            cout << two_one[i] << " " << two_two[i] << " ";
            now += 2;
        }
        for(int i = 0; ; i++){
            cout << six[i] << " ";
            now++;
            if(now == n){
                break;
            }
        }
        cout << endl;
        return 0;
    }
    for(int i = 0; i < 4999; i++){
        cout << two_one[i] << " " << two_two[i] << " ";
        now += 2;
    }
    for(int i = 0; i < 4998; i++){
        cout << three[i] << " ";
        now++;
    }
    for(int i = 0; ; i++){
        cout << six[i] << " ";
        now++;
        if(now == n){
            cout << endl;
            return 0;
        }
    }
    return 0;
}
