#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int A[200000];
    
    cin >> N;
    for(int i = 0; i < N;i++){
        cin >> A[i];
    }
    int l = 0;
    int r = N;
    while(r-l > 1){
        map<int, int> m;
        int c = (r+l)/2;
        m[A[0]] = 1;
        bool judge = true;
        for(int i = 1; i < N; i++){
            if(A[i] > A[i-1]){
                m[A[i]] = 1;
            }else{
                if(m.find(A[i]) == end(m)){
                    if(c >= 2)m[A[i]] = 2;
                    else{
                        judge = false;
                        break;
                    }
                    //cout << A[i] << ' ' << m[A[i]] << endl;
                }else{
                    for(int j = A[i]; j >= 1; j--){
                        if(m.find(j) != end(m) && m[j] < c) {
                            m[j] += 1;
                            //cout << j << ' ' << m[j] << endl;
                            break;
                        }else if(m.find(j) == end(m)){
                            m[j] = 1;
                            break;
                        }else{
                            m[j] = 1;
                        }
                        //むり
                        if(j == 1){
                            judge = false;
                            //cout << c << endl;
                        }
                    }
                    if(!judge) break;
                }
                auto iter = m.find(A[i]);
                iter++;
                m.erase(iter, end(m));
            }
        }
        if(judge){
            r = c;
        }else{
            l = c;
        }
    }
    cout << r << endl;
}