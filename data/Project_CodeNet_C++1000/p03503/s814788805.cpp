#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<functional>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector< vector<int> > F(N, vector<int>(10));
    for(int i=0; i<N; i++){
        for(int j=0; j<10; j++){
            cin >> F.at(i).at(j);
        }
    }
    vector< vector<long> > P(N, vector<long>(11));
    for(int i=0; i<N; i++){
        for(int j=0; j<11; j++){
            cin >> P.at(i).at(j);
        }
    }

    long m = -10000000000;
    for(int i=1; i<1024; i++){
        long r = 0;
        for(int j=0; j<N; j++){
            int t = i;
            int c = 0;
            for (int k=0; k<10; k++){
                if(t % 2 == 1 && F.at(j).at(k) == 1){
                    c++;
                }
                t = t >> 1;
            }
            r += P.at(j).at(c);
        }
        m = max(m, r);
    }
    cout << m << endl;
}
