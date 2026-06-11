#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int A, B, K;
cin >> A >> B >> K;
set<int> num;
int count = 0;
for(int i = A; i < A+K; i++){
    if(i <= B){
num.insert(i);
count++;
    }
}

for(int i = B-K+1; i <= B; i++){
if(i >= A){
    num.insert(i);
    count++;
}
}


for (const auto& e : num) {
cout << e << endl;
}
}
