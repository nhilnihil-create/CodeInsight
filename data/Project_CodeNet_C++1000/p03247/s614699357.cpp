    #include <bits/stdc++.h>
    using namespace std;
     
    int main(){
        int i, j, k;
        int N, X[1000], Y[1000], S[1000];
        cin >> N;
        for(i=0; i<N; i++){
            cin >> X[i] >> Y[i];
            S[i] = X[i] + Y[i];
            if((S[i] - S[0]) % 2 != 0){
                cout << -1 << endl;
                return 0;
            }
        }
     
        vector<int> values;
        for(i=30; i>=0; i--) values.push_back(1<<i);
        if(S[0] % 2 == 0) values.push_back(1);
        int M = values.size();
        cout << M << endl;
        for(i=0; i<M; i++) cout << values[i] << " \n"[i==M-1];
     
        for(i=0; i<N; i++){
            int xpy = X[i] + Y[i], xmy = X[i] - Y[i];
            for(auto&& v : values){
                if(xpy >= 0){
                    if(xmy >= 0){
                        cout << "R";
                        xpy -= v;
                        xmy -= v;
                    }else{
                        cout << "U";
                        xpy -= v;
                        xmy += v;
                    }
                }else{
                    if(xmy >= 0){
                        cout << "D";
                        xpy += v;
                        xmy -= v;
                    }else{
                        cout << "L";
                        xpy += v;
                        xmy += v;
                    }
                }
            }
            cout << endl;
        }
        return 0;
    }