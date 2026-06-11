#include <iostream>
#include <string>  
using namespace std;

int move_golem(int ini, string s, string t, string d){
    int golem_temp = ini;
    for (int i = 0; i < t.size(); i++){
        if ((golem_temp == -1) || (golem_temp == s.size())){
            break;
        } 
        if (s[golem_temp] == t[i]){
            if (d[i] == 'L'){
                golem_temp = golem_temp - 1;
            }
            else if (d[i] == 'R'){
                golem_temp = golem_temp + 1;
            }
        }
    }

    

    return golem_temp;

}

int main(){
/*    int N = 8;
    int Q = 3;
    string s = "AABCBDBA";
    string t = "ABA";
    string d = "LRR";
*/
int N;
int Q;
cin >> N >> Q;
string s;
cin >> s;

string t(Q,'a');
string d(Q,'a');
for (int i = 0; i < Q; i++){
    cin >> t[i] >> d[i];
}



    /// check lower
    int lb = -1;
    int ub = s.size();
    int lower_bound = -1;
    while ((ub - lb) > 1){
        int mid = (lb + ub)/2;
        int mid_golem_temp = move_golem(mid,s,t,d);
        if (mid_golem_temp == -1 ){
            lb = mid;
        }
        else{
            ub = mid;
        }
        lower_bound = lb;
    }

        /// check upper
    lb = -1;
    ub = s.size();
    int upper_bound = Q;
    while ((ub - lb) > 1){
        int mid = (lb + ub)/2;
        int mid_golem_temp = move_golem(mid,s,t,d);
        if (mid_golem_temp == s.size() ){
            ub = mid;
        }
        else{
            lb = mid;
        }
        upper_bound = ub;
    }
    cout << upper_bound - lower_bound - 1 << endl; 

    return 0;
}