#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> div;
    for(int i = 1; i <= sqrt(2*N); ++i) {
            if((2*N)%i==0) {
                div.push_back(i);
                div.push_back((2*N)/i);
            }
    }
    int ret = -1;
    for(auto d : div) {
        if ((2*N)/d == d-1 && d-1 <= N) {
            ret = d;
            break;
        }
    }
    if (ret == -1){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        cout << ret << endl;
        vector<vector<int> > a(ret);
        int x = 0;
        int y = 1;
        int x_num = 0;
        for(int i = 1; i <= N; ++i) {
            a[x].push_back(i);
            a[y].push_back(i);
            y++;
            x_num++;
            if(x_num == ret-1) {
                x++;
                x_num=a[x].size();
                y=x+1;
            }
        }
        for(auto aa : a) {
            cout << aa.size();
            for(auto aaa : aa) {
                cout << " " << aaa;
            }
            cout << endl;
        }
    }
    return 0;
}