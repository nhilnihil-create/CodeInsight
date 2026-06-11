#include <boost/algorithm/string/join.hpp>
#include <iostream>

using namespace std;
using namespace boost;

typedef int64_t INT;

void Resolve(istream &is, ostream &os) {
    INT A,B,C;
    is>>A>>B>>C;
    os<<((A==B)&&(A==C)?"Yes":"No");
}

#if !TEST
int main() { cin.tie(0); ios::sync_with_stdio(false); Resolve(cin, cout); cout.flush(); return 0;}
#endif
