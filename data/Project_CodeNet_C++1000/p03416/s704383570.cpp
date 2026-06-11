#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int get_reverse_num(string str);

int main(){
    int A, B;
    cin >> A >> B;

    int count = 0;
    for(int num=A; num <=B; num++){
        string str = to_string(num);
        int num2 = get_reverse_num(str);
        if(abs(num -num2)==0){
            count += 1;
        }
    }

    cout << count << endl;
    return 0;
}

int get_reverse_num(string str){
    int ans = 0;
    for(int i=0; i<str.size(); i++){
        int val = str[i] - '0';
        ans += val * (int)round(pow(10,i));
    }
    return ans;
}