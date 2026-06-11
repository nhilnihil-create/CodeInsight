#include <bits/stdc++.h>
using namespace std;
long N;
long Q;
vector<char > t_ls;
vector<char > d_ls;
string s;

bool check_left(long ind){
    for(int i=0; i< ::Q; i++){
        if(::t_ls[i] == ::s[ind]){
            if(::d_ls[i] == (char)'L'){
                ind -= 1;
            }
            else{
                ind += 1;
            }
        }
        if (ind >= N){
            return false;
        };
        if (ind <= -1){
            return true;
        }
    }
    return false;
}
bool check_right(long ind){
    for(int i=0; i< ::Q; i++){
        if(::t_ls[i] == ::s[ind]){
            if(::d_ls[i] == (char)'L'){
                ind -= 1;
            }
            else{
                ind += 1;
            }
        }
        if (ind >= N){
            return true;
        };
        if (ind <= -1){
            return false;
        }
    }
    return false;
}

int main(){
    long last;
    long ind;
    long dif;
    long tmp;
    long _sum;
    int flg;
    cin >> ::N >> ::Q;
    cin >> ::s;
    ::t_ls.resize(Q);
    ::d_ls.resize(Q);
    for(int i=0; i<Q; i++){
        cin >> ::t_ls[i] >> ::d_ls[i];
    }
    last = ::N-1;
    ind = ::N / 2;
    flg = 0;
    while(true){
        dif = abs((int)(last - ind));
        if(check_left(ind)){
            if(dif <= 1 && flg == 0){
                break;
            } else if(dif < 1){
                break;
            }
            flg = 1;
            tmp = ind;
            ind += 1 < dif / 2 ? dif / 2 : 1;
            last = tmp;
        }
        else{
            if(dif <= 1 && flg == 1){
                ind -= 1;
                break;
            } else if(dif < 1){
                ind = -1;
                break;
            }
            flg = 0;
            tmp = ind;
            ind -= 1 < dif / 2 ? dif / 2 : 1;
            last = tmp;
        }
        ind = ind > ::N-1 ? ::N-1 : ind;
        ind = ind < 0 ? 0 : ind;
    }
    _sum = ind + 1;
    last = ::N-1;
    ind = ::N / 2;
    flg = 0;
    while(true){
        dif = abs((int)(last - ind));
        if(check_right(ind)){
            if(dif <= 1 && flg == 0){
                break;
            } else if(dif < 1){
                break;
            }
            flg = 1;
            tmp = ind;
            ind -= 1 < dif / 2 ? dif / 2 : 1;
            last = tmp;
        }
        else{
            if(dif <= 1 && flg == 1){
                ind += 1;
                break;
            } else if(dif < 1){
                ind = N;
                break;
            }
            flg = 0;
            tmp = ind;
            ind += 1 < dif / 2 ? dif / 2 : 1;
            last = tmp;
        }
        ind = ind > ::N-1 ? ::N-1 : ind;
        ind = ind < 0 ? 0 : ind;
    }
    _sum += ::N - ind;
    cout << ::N - _sum << endl;
}
