#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){

ll result, a, b, c, k, s1, s2, s3;

cin >> a >> b >> c;

cin >> k;

k = pow(2,k);

s1 = a + b + c*k;

s2 = a + c + b*k;

s3 = c + b + a*k;

result = max(s1, s2);
result = max(result, s3);

cout << result << endl;



    return 0;
}