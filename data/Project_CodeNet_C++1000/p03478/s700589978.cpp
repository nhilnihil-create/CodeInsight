#include <bits/stdc++.h>          
using namespace std;

int main() {
    // input-----------------------------------------------------------
    int N, A, B;
    cin >> N >> A >> B;
    
    //calculate--------------------------------------------------------
    vector<vector<int>> vec_1(N,vector<int>(5));
    vector<int> vec_2(N);
    vector<int> vec_3(N);
    //vec_1-------------------------------
    for (int i=0; i<N; i++) {
        int v5, v4, v3, v2;
        v5 = vec_1.at(i).at(4) = (i+1)/10000;
        v4 = vec_1.at(i).at(3) = ((i+1)-v5*10000)/1000;
        v3 = vec_1.at(i).at(2) = ((i+1)-v5*10000-v4*1000)/100;
        v2 = vec_1.at(i).at(1) = ((i+1)-v5*10000-v4*1000-v3*100)/10;
        vec_1.at(i).at(0) = (i+1)-v5*10000-v4*1000-v3*100-v2*10;
    }
    //vec_2-------------------------------
    for (int i=0; i<N; i++) {
        for (int j=0; j<5; j++) {
            vec_2.at(i) += vec_1.at(i).at(j);
        }
    }
    //vec_3-------------------------------
    for (int i=0; i<N; i++) {
        vec_3.at(i) = i+1;
    }
    //count-------------------------------
    int count = 0;
    for (int i=0; i<N; i++) {
        if (vec_2.at(i) >= A && vec_2.at(i) <= B) {
            count += vec_3.at(i);
        }
    }

    //output--------------------------------------------------------
    cout << count << endl;
}