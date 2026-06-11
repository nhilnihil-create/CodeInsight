#include <iostream>
#include <regex>
using namespace std;

int main(void) {
    regex re1("^.*keyence$");
    regex re2("^k.*eyence$");
    regex re3("^ke.*yence$");
    regex re4("^key.*ence$");
    regex re5("^keye.*nce$");
    regex re6("^keyen.*ce$");
    regex re7("^keyenc.*e$");
    regex re8("^keyence.*$");
    string S;cin>>S;
    if (regex_search(S, re1)||regex_search(S, re2)||regex_search(S, re3)||regex_search(S, re4)||regex_search(S, re5)||regex_search(S, re6)||regex_search(S, re7)||regex_search(S, re8)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}