#include <iostream>
#include <vector>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

const int lim = 55555;
bool num[(lim+1)*5];

bool addible(vector<int> nums, int next){
    bool fl = true;
    for(int i=0; i<nums.size();i++ ){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                for(int l=k+1; l<nums.size(); l++){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(num[sum+next]) fl = false;
                }
            }
        }
    }
    return fl;
}

int main(){
    int N;
    cin >> N;

    fill(num, num+lim, true);
    num[0] = false;
    num[1] = false;

    vector<int> p;
    for(int i=2; i<=lim*5; i++){
        int t = 2;        
        while(i*t<=lim){
            num[i*t] = false;
            t++;
        }
        if(num[i] && i<=lim) p.push_back(i);
    }

    vector<int> ans;
    for(auto m : p){
        if(ans.size() == N) break;
        if(m % 5 == 1) ans.push_back(m);
    }

    for(auto m : ans){
        cout << m << " ";
    }
    cout << endl;

    return 0;
}
